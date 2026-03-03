/* 
 * class AudioCue 
 * controls a synth to allow live synthesis
 * 
 * by F. Vriezenga, March 2018
 */ 

using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public struct Adsr {
	public double[] ampValues { get; set; }
	public double[] durValues { get; set; }
	public int numValues { get; set; } 
}


public class Envelope : Generator {
	private double[] ampValues;
	private double[] durValues;
	private int numValues; 
	private int currentIndex = -1;
	private double phase = 0;
	private double phaseIncrement = 0;
	private double slope = 0;
	private double startValue = 0;
	private double endValue = 0;


	//____________ CONSTRUCTOR ____________ 
	public Envelope(Clock clock, double samplerate, Adsr adsr) : 
	base(clock, samplerate) {
		//TODO add checks if e.g. durValues are 1 size smaller then ampValues, etc. 
		this.ampValues = adsr.ampValues;
		this.durValues = adsr.durValues;
		this.numValues = adsr.numValues;
	}


	//____________ PUBLIC METHODS ____________ 
	public override void Tick()
	{
		//if envelope is running
		if (currentIndex != -1) {
			//increment phase
			phase += phaseIncrement; 
			//check if phase exceeds end
			if (phase > 1.0) {
				//either we are ready to start next slope or we are done
				if (nextIndex () != -1) {
					calculateSlope ();
				} else {
					//done with envelope, don't calculate sample
					return;
				}
			}
			calculateSample ();
		}
	}

	//start or reset adsr
	public void run() {
		currentIndex = 0;
		calculateSlope();
	}


	//____________ PROTECTED METHODS ____________ 
	protected void calculateSlope() {
		//be sure were not at the end of the envelope
		if (currentIndex >= 0 && currentIndex + 1 < numValues) {			
			startValue = ampValues[currentIndex];
			endValue = ampValues [currentIndex + 1];
			phase = 0;
			phaseIncrement = 1 / (samplerate * durValues [currentIndex]);
			slope = endValue - startValue;
		} else {
			//.... at end or something gone wrong. 
			Debug.Log("Envelope.calculateSlope -> something gone wrong???");
		}
	}
		

	//calculates the next sample
	protected void calculateSample() {
		sample = startValue + phase * slope;
	}

	protected int nextIndex() {		
		currentIndex++;
		if (currentIndex + 1 >= numValues) {			
			currentIndex = -1;
			sample = 0;
		}
		return currentIndex;			
	}

	//TODO - add getters and setters, to enable change of adsr values
}



