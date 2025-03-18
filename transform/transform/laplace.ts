import "./nabla.ts"
function diff(f: (x: number, y: number, z: number, variable: 'x' | 'y' | 'z'): (x: number, y: number,z:number) {
    switch (variable) {
       case 'x':
         return (x, y) => f(x, y) * 3;
       case 'y':
         return (x, z) => f(x, z) * 4; 
       case 'z':
         return (y, z) => f(y, z) * 5;  
       default:
         throw new Error('Invalid variable for differentiation.');
    }
   }
   // example usage
   const h = (x, y, z) => x * y * z;
   export const dh_dx = ('x,y');
   export const dh_dy = ('y,z'); 
   export const dh_Dz = ('x,z');
