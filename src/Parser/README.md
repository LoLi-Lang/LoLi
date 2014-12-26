Tokenizer and Parser Design
====

The Tokenizer and Parser defines the syntax of the Language.
The current syntax definition borrows much ideas from Scheme
specifications [R7RS](http://www.scheme-reports.org/) sixth draft.
The first versions of the language might not implement all the features.


## Tokenizer

There are following token types in the language:

### identifier

An identifier is a sequence of alphabetic characters, digits and
"extended identifier characters" that's not starting with digits.
"extended identifier characters include the following":

! $ % & \* + - . / : = > ? @ ^ \_ ~

For the time being, inline hex escape and vertical bars are not supported.

Here are some valid identifiers:

* lambda
* q
* list->vector
* +soup+
* +
* V17a
* <=?
* a34kTMNs
* ->string
* ...
* this-is-a-very-long-id


Also for ease of things, identifiers are case-sensitive.


### boolean

\#true and \#false, in short, \#t and \#f

### number

For now integers, float and double would be supported.
For integers, bin, oct, dec and hex would be supported

* bin: #b10100
* oct: #o24
* dec: #d20 20
* hex: #d14
* float: 3.1415 4.5e4
* double: 2.3d3 2.3D3

### string

Anything between the quote mark is a string, with no quotemark inside
that's not behind a single '\'.

"\"To be or not to be?\" He whispered to himself."

'\' serves as a escape sign, the following characters could be escaped:

* \a bell char
* \b backspace char
* \t tab
* \n return
* \r return
* \" quotemark
* \\\\ backslash
* \\<line ending> escaped line ending. Continue with next line.


### Tokenizer specifications

```
token -> <identifier>
       | <boolean>
       | <number>
       | <char>
       | <string>
       | (
       | )
       | #(
       | #u8
       | '
       | `
       | ,
       | ,@
       | .
```


## Parser and Language Syntax




```
<expression> −> <identifier>
              | <literal>
              | <procedure call>
              | <lambda expression>
              | <conditional>
              | <assignment>
              | <derived expression>
              | <macro use>
              | <macro block>
```
