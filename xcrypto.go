package main

import (
	"github.com/jurgen-kluft/xcode"
	"github.com/jurgen-kluft/xcrypto/package"
)

func main() {
	xcode.Init()
	xcode.Generate(xcrypto.GetPackage())
}
