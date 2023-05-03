package ccrypto

import (
	cbase "github.com/jurgen-kluft/cbase/package"
	"github.com/jurgen-kluft/ccode/denv"
	cunittest "github.com/jurgen-kluft/cunittest/package"
)

// GetPackage returns the package object of 'ccrypto'
func GetPackage() *denv.Package {
	// Dependencies
	unittestpkg := cunittest.GetPackage()
	basepkg := cbase.GetPackage()

	// The main (ccrypto) package
	mainpkg := denv.NewPackage("ccrypto")
	mainpkg.AddPackage(unittestpkg)
	mainpkg.AddPackage(basepkg)

	// 'ccrypto' library
	mainlib := denv.SetupDefaultCppLibProject("ccrypto", "github.com\\jurgen-kluft\\ccrypto")
	mainlib.Dependencies = append(mainlib.Dependencies, basepkg.GetMainLib())

	// 'ccrypto' unittest project
	maintest := denv.SetupDefaultCppTestProject("ccrypto_test", "github.com\\jurgen-kluft\\ccrypto")
	maintest.Dependencies = append(maintest.Dependencies, unittestpkg.GetMainLib())
	maintest.Dependencies = append(maintest.Dependencies, basepkg.GetMainLib())
	maintest.Dependencies = append(maintest.Dependencies, mainlib)

	mainpkg.AddMainLib(mainlib)
	mainpkg.AddUnittest(maintest)
	return mainpkg
}
