const Quack = require('./NativeQuack').default;

export function multiply(a: number, b: number): number {
  return Quack.multiply(a, b);
}
