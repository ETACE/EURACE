For Installation and usage see UserGuide.pdf.

Converting documentation:
latex2html -no_subdir -split 0 -no_navigation UserGuide.tex
pdftotext -layout UserGuide.pdf 

Testing:
svn export http://ccpforge.cse.rl.ac.uk/svn/eurace/models/ALM/alm_tags/Model_UNIBI_after_Genoa_rev1039_at_1053
svn export http://ccpforge.cse.rl.ac.uk/svn/xagents/tags/xparser/0.15/xparser_0.15.10/
#See http://www.eurace.org/Wiki/index.php/System_requirements_for_FLAME_and_Libmboard
svn export http://ccpforge.cse.rl.ac.uk/svn/xagents/trunk/libmboard/
sudo aptitude install libtool automake
cd libmboard:
    ./autogen.sh
    ./configure --disable-tests --disable-parallel
    make
    sudo make install
make xparser, then parse model and compile 

Making a release:
latex2html -no_subdir -split 0 -no_navigation UserGuide.tex
pdir=popgui-$(./popgui.py -v)
mkdir $pdir
cp poplib.py popgui.py UserGuide.pdf $pdir/
zip -r $pdir.zip $pdir
ver=$(./popgui.py -v)
cd ..
	svn mkdir tags/$ver
	svn copy trunk/popgui.py tags/$ver/
	svn copy trunk/poplib.py tags/$ver/
	svn copy trunk/UserGuide.tex tags/$ver/
    svn copy trunk/screenshots tags/$ver
	#svn copy trunk/UserGuide.html tags/$ver/

Benchmarking:
   python /usr/lib/python2.5/cProfile.py -o PROFILE1.txt popgui.py pipponovo.pop
   then instantiate population.
   then in Python interpreter:
   >>> import pstats
   >>>
http://guppy-pe.sourceforge.net/#Heapy
sudo opcontrol --no-vmlinux
sudo opcontrol --start
DO WHATEVER 
sudo opcontrol --stop

