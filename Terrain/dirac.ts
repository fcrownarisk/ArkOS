interface DiracMatrix {
    gamma1: M1;
    gamma2: M2;
    gamma3: M3;
    gamma4: M4;
  }
namespace HarmonicOscillator {
    alpha: X;
    beta: Y;
    lambda: Z;
    zeta: T;
}

type Matrix = [number, number][];

const i = Math.sqrt(-1);

function Matrix() {
    const gamma1 = [[1, 0], [0, 1]];
    const gamma2 = [[0, 1], [1, 0]];
    const gamma3 = [[1, i], [i, 1]];
    const gamma4 = [[i, 1], [1, i]];
  }
