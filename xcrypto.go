package main

import (
	"github.com/jurgen-kluft/xcode"
	"github.com/jurgen-kluft/xcrypto/package"
)

func main() {
	xcode.Generate(xcrypto.GetPackage())
}
