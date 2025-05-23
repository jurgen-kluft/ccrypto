package ccrypto

import (
	cbase "github.com/jurgen-kluft/cbase/package"
	denv "github.com/jurgen-kluft/ccode/denv"
	ccore "github.com/jurgen-kluft/ccore/package"
	cunittest "github.com/jurgen-kluft/cunittest/package"
)

// GetPackage returns the package object of 'ccrypto'
func GetPackage() *denv.Package {
	// Dependencies
	unittestpkg := cunittest.GetPackage()
	cbasepkg := cbase.GetPackage()
	ccorepkg := ccore.GetPackage()

	// The main (ccrypto) package
	mainpkg := denv.NewPackage("ccrypto")
	mainpkg.AddPackage(unittestpkg)
	mainpkg.AddPackage(cbasepkg)
	mainpkg.AddPackage(ccorepkg)

	// 'ccrypto' library
	mainlib := denv.SetupCppLibProject("ccrypto", "github.com\\jurgen-kluft\\ccrypto")
	mainlib.AddDependencies(cbasepkg.GetMainLib()...)
	mainlib.AddDependencies(ccorepkg.GetMainLib()...)

	// 'ccrypto' unittest project
	maintest := denv.SetupDefaultCppTestProject("ccrypto_test", "github.com\\jurgen-kluft\\ccrypto")
	maintest.AddDependencies(unittestpkg.GetMainLib()...)
	maintest.AddDependencies(cbasepkg.GetMainLib()...)
	maintest.AddDependencies(ccorepkg.GetMainLib()...)
	maintest.Dependencies = append(maintest.Dependencies, mainlib)

	mainpkg.AddMainLib(mainlib)
	mainpkg.AddUnittest(maintest)
	return mainpkg
}
