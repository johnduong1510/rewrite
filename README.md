#1. 
- Eliminate variable: a2a, v5, v15 or v7 (duplicate),v13.
- Eliminate pointer: *v4 => use *a2 directly.
- Change complicated syntax like *(int *)v11,*(int *)v11 into a2[i++],a[i]. These are represented by variable a and b.
- 2 Lines below:
v13 = *(int *)(v12 + 4); => Get value of next element in a2 array.
v12 += 4; => get address of next element in a2 array.
Can be simpler by b=a2[++i].
- Line o1=a2a++ +1 => ++o1, a2a is unnecessary.
- After print out variables on console, i realize when v9 negative, choose minnimum of a and b to go to next loop. When v9 positive, choose maximum of a and b.

#2. Because of pre-condition, a4 array can changed, and return value. I print out them all of original function and rewrite function. Compare them.

#3 The function acts like a filter. When amplitude of 2 elements in array greater than pre-condition value, and v9 positive. Taking the maximum of these elements, when v9 negative, take the minimum one. Otherwise, jump to next elements and go to loop. The return value is total numbers of elements taken out from a2 array.
     

