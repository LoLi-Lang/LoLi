Syntax
======

There are two basic elements in LoLi: Atom and List, where Atom can be an
element that is of any non-List types (nor sub-types of List). This is
similar to other LISP dialects.

A legal expression in LoLi can contain:

1. a single Atom, e.g.: `1`, `"String"`, `:NUM`, `Symbol`, `nil`
2. a List (Including empty list `'()`), e.g.: `(+ 1 2)`, `(def var 123)`,
  `(:a 1 :b 2 :c 3)`
  - for a List to be evaluated, it must be in a form as a tree that only
    the children nodes are nouns, e.g.: (V (V (V N) N) N N N (V N))
  - where verbs are Function type (and its sub-types, like Lambda and
    Procedure)
3. either form 1 or form 2 with a quote `'`, a quotaion is considered
  as a List, `(quote foo)` equals to `'foo`
4. special operator followed by specific element, that are not
  implemented / planned yet

To support the Context-based inferrence, there are some special design
of the Lambda expression in LoLi, inspired by the System-F.

In LoLi, a type id inside a Lambda expression is required, so it looks like
`(\\ :type (x) (exp))` (equivalent to `.\xTtype` in Systen F). Therefore a
legal Lambda expression in LoLi can look like `(\\ :int (x (y :int)) (+ x y))`,
where `x` can be an element of any type and `y` must be an element of type INT
(and its sub-types).

To make a generic return in Lambda expression, you can simply use `:OBJ` for
the type of that Lambda expression, since `:OBJ` is the base type of all types
in LoLi.

The namespace (environment) of the Inferrence system can contain a multiple
bind of one symbol to make LoLi more similar to human language, you can leave
the type inferrence to the interpreter (e.g.
`[ (a . 1) (a . "String") (a . #<Lambda INT->INT>) ]` is a legal environment).
If you want to specify a type, you can use `get-type` followed by a symbol
and a type id, e.g.: `(get-type a :int)`

For the environment above, you can use the Lambda expression `a` in either way:
`(a a)`, `(a (get-type a :int))`

Function `def` binds a symbol to an element, `(def a 1)`, `(def a "String)`,
`(def a (\\ ... ))`

Function `set!` will change the value bind to a symbol, `(set! a 2)` will make
the bind (a . 1) into (a . 2), `(set! (get-type a :flt) 2)` will change the
float number bind to a into 2 (the bind must exists first, otherwise you
should use `def` to create a new bind)

There is no `&body` or `&rest` features in LoLi and the argument list must have
a certain arity. If you really want to use a vaiable argument list, put them
into a List: `(\\ :type (a b c (rest :LIST)) exp)`

Misc
----

The BOOLEAN type in LoLi is a sub-type of KEYWORD, so they look like: `:true`,
`:false` instead of the Scheme style `#true`, `#false`.

There also exist `T` and `NIL`, they are SYMBOLs, and DO NOT have BOOLEAN value,
`NIL` equals to `'()`.

The type ids are also KEYWORDs.

You can extend types by creating sub-types (which is not implemented yet)
