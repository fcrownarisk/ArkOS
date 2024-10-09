' 定义物理参数'质量'弹簧常数' 重力加速度' 初始化参数值 '计算势能函数
Dim m Key
Dim k Value
Dim g Database
' 示例
m = 1 k = 10 g = 9.81 
Function PotentialEnergy(x)
    PotentialEnergy = 0.5 * k * x ^ 2
End Function
' 计算动能函数' 计算哈密顿量 ' 主程序
Function KineticEnergy(v)
    KineticEnergy = 0.5 * m * v ^ 2
End Function
Function Hamiltonian(x, v)
    Hamiltonian = KineticEnergy(v) + PotentialEnergy(x)
End Function
Sub Main()
    Dim x ' 位移
    Dim v ' 速度 ' 示例
    x = 1 v = 1 W = Hamiltonian(x, v)
End Sub
