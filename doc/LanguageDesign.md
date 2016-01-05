Language Design of LoLi1
========================

<small>Z.Shang
2014

THIS ONE IS OUTDATED, DETAILS MAY BE DIFFERENT FROM THE IMPLEMENTATION</small>

LoLi is a Lisp dialect that combines Lisp - 1 and Lisp - 2, that means in LoLi
there will be one namespace but supporting duplicated name, and the interpreter
will infer the value based on the comtext (or by manully specified).

Here is the language design of LoLi:

Basic Symbols
-------------

| Symbol       | Description                                         |
|--------------|-----------------------------------------------------|
|`T`           | same as `T` in Common Lisp, but not Boolean true.   |
|`NIL`         | same as `NIL` in Common Lisp, but not Boolean false.|
|`set!`        | same as `SET!` in Scheme                            |
|`def`         | like `define` in Scheme or `defvar` in Common Lisp, or `def` in Arc (`(defvar foo #'(lambda ...)` when defining a lambda expression)|
|`\`           | `lambda (\ :TYPE-ID (arg-lst) (exp))`               |
|`let`         | same as `LET` in Common Lisp                        |
|`quote("\'")` | same as `QUOTE` in Common Lisp/Scheme               |

Naming Regulation
-----------------

| What             | How                                             |
|------------------|-------------------------------------------------|
|Predicate         | end with `?` (E.g. `null?`)                     |
|Destructive       | end with `!` (E.g. `set!`)                      |
|Recursive Function| end with `-r` (E.g. `map-r`)                    |
|Global Variable   | surround by `**` (E.g. `*TOP-LEVEL*`)           |
|Function          | use hyphen-connected full spelling (E.g. `number-of-count` but not `numOfCount`)|
|Argument          | use "lst" for list, "num" for number, "sym" for symbol|
|Commentary        | add comments to the function's parameter and returning type (E.g. ;;Num -> Num)|

Core Data Structure
-------------------

LoLi Objects as defined in `loli_types.h` (the list structured memory):

```C++
struct loliObj {
	loliType  type;  /// enum of types
	string    value; 
	loliObj   *head; /// Pointer to head(loliObj)
	loliObj   *tail; /// Pointer to tail(loliObj)
	loliObj   *env;  /// Pointer to environment
	procedure *proc; /// Pointer to procedure
	// ...
};
```

Environment
-----------

The environment itself is a LoliObj:

```Lisp
([syma . a] ([symb . b] ([symc . c] ( ... ([symn . n] . nil)))))
; using [] and () just to be clear for reader, in LoLi there will only be ( and )
```

- Lookup:
	Will return a list that contains all the symbols that matches the criteria
- Insert:
	Insert the new item while adding to environment to make the environment in
	accending order, that makes environment easier to be looked up

A procedure in LoLi_ENV:

	+-----------------------------------------------+
	|		   Env Entry			|
	+-----------------------------------------------+
	|   +----------------------------------------+	|
	|   |   	     cons		     |	|
	|   +----------------------------------------+	|
	|   |		Symbol (Identifier)	     |	|
	|   |    +------------------------------+    |	|
	|   |    |  	     cons		|    |	|
	|   |    +------------------------------+    |	|
	|   |    |    loliType (Input type)	|    |	|
	|   |    |   loliObj proc (Procedure)	|    |	|
	|   |    +------------------------------+    |  |
	|   +----------------------------------------+	|
	+-----------------------------------------------+

### Context Based Meaning Inference (CBMI)

Parse the input into AST, then lookup the corresponding obj in the environment.
	
Key concepts for the CBMI:
- Verb : Objects that takes other Objects, for example: Function (`PROC`) and
  Lambda (`LAMBDA`)
- Noun : Objects that only have value, for example: Symbol (`SYM`), Number
  (`INT` / `FLT`), etc.
