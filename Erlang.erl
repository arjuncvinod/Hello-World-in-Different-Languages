-module(hello).
-export([world/0]).

world() ->
    io:format("Hello, World!~n").
