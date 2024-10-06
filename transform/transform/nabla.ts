declare module X{}
declare module Y{}
declare module Z{}
type NablaOperator<T extends Record<string, any>> = (field: keyof T) => T[keyof T];
interface VectorField {
 x: number;
 y: number;
 z: number;
}
function gradient(X:Text,Y:TextDecoder,Z:TextEncoder){
    X: Math.sin(NaN)
    Y: Math.cos(NaN)
    Z: Math.tan(NaN)
}