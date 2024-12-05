<h2 align="center">is even?</h2>

> js lib to check if a given number is even. just like the others libs but better. why? because i made it.

### install

```
npm i is_even_ee
```

### usage

```js
import "is_even_ee";

const is_even = (1).isEven();

console.log(is_even); // => false;
```

### benchmark

#### using the "right way" to check if a number is even. 🤢🤮🤮😖

```js
const isEven = (num) => num % 2 === 0;

const start = Date.now();
const is_even = isEven(1);
const finish = Date.now();

console.log(is_even); // => false;
console.log((finish - start) / 1000); // => 0.001s
```

#### using the coolest way. 😎😎😎🤑

```js
import "./is_even_ee";

const start = Date.now();
const is_even = (1).isEven();
const finish = Date.now();

console.log(is_even); // => false;
console.log((finish - start) / 1000); // => 8.028s