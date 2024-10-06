import "./compute/Coodinate/movement.c"
declare module X{}
declare module Y{}
declare module Z{}
function XYZ(){
    this.X = this.i & this.j | this.k
    this.Y = this.j & this.k | this.i
    this.Z = this.k & this.i | this.j
}
function xyzt(){
    this.x = this.x * this.X / this.t
    this.y = this.y * this.Y / this.t
    this.z = this.z * this.Z / this.t
}
void xyzt();{
function x1y1z1t1(){
    this.l = this.X + this.x
    this.m = this.Y + this.y
    this.n = this.Z + this.z
}
function x2y2z2t2(){
    this.o = this.i + this.j
    this.p = this.k + this.l
    this.q = this.l + this.i
}
}