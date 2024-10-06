Dim kineticEnergy ' 系统的动能
Dim potentialEnergy ' 系统的势能
Dim lagrangian ' 拉格朗日量

kineticEnergy = "1/2 * m * qDot ^ 2" ' 动能的表达式
potentialEnergy = "V(q)" ' 势能的表达式，这里假设势能是关于q的函数
lagrangian = kineticEnergy & " - " & potentialEnergy ' 拉格朗日量的表达式