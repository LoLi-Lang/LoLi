-module(loli_typeclass).
-export([new_type/3, sub_type_p/2, new_related_type/3, new_compound_type/2]).

new_type(Name, Id, Parent) -> {'loli_basic_type', {Name, Id, Parent}}.

new_related_type(Fn, Base, Target) -> {'loli_related_type', {Fn, Base, Target}}.

new_compound_type(R, S) -> {'loli_compund_type', {R, S}}.

sub_type_p(_ = {'loli_basic_type', {_, _, _}}, _ = {'loli_basic_type', {"Object", obj, nil}}) ->
    true;

sub_type_p(_ = {'loli_basic_type', {X, Y, Z}}, _ = {'loli_basic_type', {X, Y, Z}}) ->
    true;

sub_type_p(_ = {'loli_basic_type', {"Object", obj, nil}}, _ = {'loli_basic_type', {_, _, _}}) ->
    false;

sub_type_p(_ = {'loli_basic_type', {_, _, Parent}}, T = {'loli_basic_type', {_, _, _}}) ->
    sub_type_p(Parent, T);

sub_type_p(_ = {'loli_compound_type', {X, Y}}, _ = {'loli_compound_type', {X, Y}}) ->
    true;

sub_type_p(_ = {'loli_compound_type', {A = {'loli_basic_type', {_, _, _}}, B = {'loli_basic_type', {_, _, _}}}},
           _ = {'loli_compound_type', {C = {'loli_basic_type', {_, _, _}}, D = {'loli_basic_type', {_, _, _}}}}) ->
    sub_type_p(A, C) and sub_type_p(B, D);

sub_type_p(_, _) ->
    false.
