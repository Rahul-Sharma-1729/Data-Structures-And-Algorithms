- Important thing to keep in mind, the depth idea can only be used in single symbol problem

- We should keep in mind the idea of the graph since later we could also be asked these things in range queries like Q queries [5,10],[2,19].... tell if the brackets are balanced or not and we should be able to give the answer quick, so for this we would have to precompute the depth variable array and then use the idea of balance only being there:
  - if the start value and the final value are equal
  - depth variable should not be going lower than start value at any point of time.
  - for the min query in the range we could use segment trees

- The stack idea is extensible for many different symbols
