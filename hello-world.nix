{ pkgs ? import <nixpkgs> {} }:

pkgs.writeText "hello-world.nix" ''
  builtins.trace "Hello, World!" ""
''

# note: you must build this and then it will run. 
