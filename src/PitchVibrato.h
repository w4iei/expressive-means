
/*
    Expressive Means Pitch Vibrato

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.  See the file
    COPYING included with this distribution for more information.
*/

#ifndef EXPRESSIVE_MEANS_PITCHVIBRATO_H
#define EXPRESSIVE_MEANS_PITCHVIBRATO_H

#include <vamp-sdk/Plugin.h>

#include "CoreFeatures.h"

using std::string;

#define WITH_DEBUG_OUTPUTS 1

class PitchVibrato : public Vamp::Plugin
{
public:
    PitchVibrato(float inputSampleRate);
    virtual ~PitchVibrato();

    string getIdentifier() const;
    string getName() const;
    string getDescription() const;
    string getMaker() const;
    int getPluginVersion() const;
    string getCopyright() const;

    InputDomain getInputDomain() const;
    size_t getPreferredBlockSize() const;
    size_t getPreferredStepSize() const;
    size_t getMinChannelCount() const;
    size_t getMaxChannelCount() const;

    ParameterList getParameterDescriptors() const;
    float getParameter(string identifier) const;
    void setParameter(string identifier, float value);

    ProgramList getPrograms() const;
    string getCurrentProgram() const;
    void selectProgram(string name);

    OutputList getOutputDescriptors() const;

    bool initialise(size_t channels, size_t stepSize, size_t blockSize);
    void reset();

    FeatureSet process(const float *const *inputBuffers,
                       Vamp::RealTime timestamp);

    FeatureSet getRemainingFeatures();

protected:
    int m_stepSize;
    int m_blockSize;
    
    CoreFeatures m_coreFeatures;

    CoreFeatures::Parameters m_coreParams;

    struct VibratoElement {
        int hop;
        int peakIndex;
        double peakHeight; // min-to-max, in semitones
        double position; // in seconds, interpolated for position
        double waveLength; // time to the following element's position
        double correlation;
        VibratoElement() :
            hop(-1), peakIndex(-1),
            peakHeight(0.0), position(0.0),
            waveLength(0.0), correlation(0.0) { }
    };
    
    mutable int m_pitchTrackOutput;

/*!!!
    mutable int m_summaryOutput;
    mutable int m_pitchvibratoTypeOutput;
    mutable int m_pitchvibratoIndexOutput;
*/

#ifdef WITH_DEBUG_OUTPUTS
    mutable int m_rawPeaksOutput;
    mutable int m_acceptedPeaksOutput;
    mutable int m_vibratoPitchTrackOutput;
#endif

};

#endif
