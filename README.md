# cpp-ast
Implementation of a parser and evaluator for arithmetic expressions based on abstract syntax tree (AST)
```
test("3 + (7-2) * 4 / 2");
```

```
⚫ 3 + (7-2) * 4 / 2 = 13
2D Representation of AST
--------------------------------


                                        4

                              *

                                                  2

                                        /

                                                  1

                    *

                                                            1

                                                  *

                                                            2

                                        -

                                                  0

                              +

                                                  1

                                        *

                                                  7

          +

                    0

+

                    1

          *

                    3
--------------------------------
```

## Limitations
* Only numbers from 0 to 9 are allowed as input
* Only binary operators '+', '-', '*', '/' and parentheses '(', ')' are allowed
* Negative input or unary minus is not allowed

Program will throw an error just like this:
```
test("12 - 1");
test("1.5 + 2");
test("2 + (-1)");
```

```
The input '12 - 1' is invalid (literal is too large)
The input '1.5 + 2' is invalid (unexpected token)
The input '2 + (-1)' is invalid (either negative literal or unary minus)
```

## References

* https://mariusbancila.ro/blog/2009/02/03/evaluating-expressions-part-1/
* https://unclechromedome.org/c++-tutorials/expression-parser/index.html
