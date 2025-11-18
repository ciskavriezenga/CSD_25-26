

// Example of a simple audio flow with one noise oscillator 
// combined with an amp
noiseSignal = noise.getSignal();
noiseSignal *= amp;
output = noiseSignal


// FM pseudocode
// carrier, modulator objects are sine oscillators
// modDepth = 0.5 of modulation range 
modulationSignal = modulator.getSample() * modDepth;
carrier.setFreq(modulationSignal + carrierFreq);
sample = carrier.getSample() 



