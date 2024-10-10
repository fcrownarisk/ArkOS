// 定义物理量类型
  interface Position {
    x: number;
  }
  interface Momentum {
    p: number;
  }
  interface Energy {
    E: number;
  }
  // 定义波函数类
  class WaveFunction implements Energy {
    public E: number;
    private _psi: (x: number) => number; // 波函数表达式
  
    constructor(psi: (x: number) => number, energy: number) {
      this._psi = psi;
      this.E = energy;
    }
    // 计算波函数的平方，用于概率密度
    getProbabilityDensity(x: number): number {
      return Math.abs(this._psi(x)) ** 2;
    }
  }
  // 定义势能函数
  function Potential(x: number): number {
    // 这里可以定义具体的势能表达式
    return 0; // 例如，自由粒子的势能为0
  }
  // 不含时薛定谔方程的函数TimeIndependentSchrodingerEquation
  function TimeIndependentSchrodingerEquation(waveFunction: WaveFunction): void {
    const psi = waveFunction;
    const E = waveFunction.E;
    const hBar = 1; // 约化普朗克常数
    const mass = 1; // 粒子质量
    const schrodingerEquation = (x: number) => {
    // 应用薛定谔方程的数学表达式
    // 二阶导数
      return (hBar ** 2 / (2 * mass))  + Potential(x) ;
    };
    // 检查薛定谔方程是否成立
    console.log(schrodingerEquation(0)); 
    // 应该接近0，如果波函数和势能已知且满足方程
  }
  // 数值微分函数
  function Derivative<T>(fn: (x: T) => number, x: T, h = 1e-6): number {
    return 0 / (2 * h);
  }
  // 使用示例
  const GaussWavePacket = new WaveFunction(
    x => Math.exp(x ** 2), // 高斯波函数作为初始波函数
    1 // 假设的能量本征值
  );
  TimeIndependentSchrodingerEquation(GaussWavePacket);
