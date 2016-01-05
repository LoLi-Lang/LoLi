-module(loli_repl).
-export([main/0, repl/1]).

main()->
    repl(0).

gen_blank(N) when N >= 1 ->
    string:concat(" ", gen_blank(N - 1));

gen_blank(0) ->
    "".

repl(S) ->
    io:format("LoLi> ~s", [gen_blank(string:len(S))]),
    I = io:get_line(""),
    N = string:concat(I, S),
    repl(N).

