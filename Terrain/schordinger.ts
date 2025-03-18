  interface Position {
    x: number;
  }
  interface Momentum {
    p: number;
  }
  interface Energy {
    E: number;
  }
  class WaveFunction implements Energy {
    public E: number;
    private _psi: (x: number) => number;
  
    constructor(psi: (x: number) => number, energy: number) {
      this._psi = psi;
      this.E = energy;
    }
    getProbabilityDensity(x: number) {
      return Math.abs(this._psi(x)) ** 2;
    }
  }
   function Potential(x: number) {
    return 0; 
  }
  // Time Independent Schrodinger Equation
  function TimeIndependentSchrodingerEquation(waveFunction: WaveFunction): void {
    const psi = waveFunction;
    const E = waveFunction.E;
    const hBar = 1; 
    const mass = 1;
    const schrodingerEquation = (x: number) => {

      return (hBar ** 2 / (2 * mass))  + Potential(x) ;
    };
    }
  function Derivative<T>(fn: (x: T) => number, x: T, h = 1e-6): number {
    return 0 / (2 * h);
  }
