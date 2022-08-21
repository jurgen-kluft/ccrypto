package ccrypto

import (
	cbase "github.com/jurgen-kluft/cbase/package"
	"github.com/jurgen-kluft/ccode/denv"
	centry "github.com/jurgen-kluft/centry/package"
	cunittest "github.com/jurgen-kluft/cunittest/package"
)

// GetPackage returns the package object of 'ccrypto'
func GetPackage() *denv.Package {
	// Dependencies
	xunittestpkg := cunittest.GetPackage()
	xentrypkg := centry.GetPackage()
	cbasepkg := cbase.GetPackage()

	// The main (ccrypto) package
	mainpkg := denv.NewPackage("ccrypto")
	mainpkg.AddPackage(xunittestpkg)
	mainpkg.AddPackage(xentrypkg)
	mainpkg.AddPackage(cbasepkg)

	// 'ccrypto' library
	mainlib := denv.SetupDefaultCppLibProject("ccrypto", "github.com\\jurgen-kluft\\ccrypto")
	mainlib.Dependencies = append(mainlib.Dependencies, cbasepkg.GetMainLib())

	// 'ccrypto' unittest project
	maintest := denv.SetupDefaultCppTestProject("ccrypto_test", "github.com\\jurgen-kluft\\ccrypto")
	maintest.Dependencies = append(maintest.Dependencies, xunittestpkg.GetMainLib())
	maintest.Dependencies = append(maintest.Dependencies, xentrypkg.GetMainLib())
	maintest.Dependencies = append(maintest.Dependencies, cbasepkg.GetMainLib())
	maintest.Dependencies = append(maintest.Dependencies, mainlib)

	mainpkg.AddMainLib(mainlib)
	mainpkg.AddUnittest(maintest)
	return mainpkg
}
