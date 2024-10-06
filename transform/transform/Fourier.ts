class ComplexNumber {
    constructor(public real: number, public imaginary: number) {}
   }
function discreteFourierTransform(signal: number[]): ComplexNumber[] {
    const n = signal.length;
    const result: ComplexNumber[] = new Array(n);
   
    for (let k = 0; k < n; k++) {
       let sum = 0;
       for (let t = 0; t < n; t++) {
         sum += signal[t] * Math.exp(-2 * Math.PI * k * t / n);
       }
       result[k] = new ComplexNumber(sum, 0);
    }
   
    return result;
   }
