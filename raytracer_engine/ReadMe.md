<h1>USAGE: ./raytracer <SCENE_FILE> <path/to/file></h1>

<b>SCENE_FILE:</b> scene configuration
<b>path/to/file</b> : Path to the file where you want to save your image (without extensions), you can change it by
sfml for use the sfml to draw the scene
or put nothing for get all the image pixels writed on the standard output

NOTE: if on run time you encounter the following error :
  error while loading shared libraries: libconfig++.so.xx: cannot open shared object file: No such file or directory

  use:     export LD_LIBRARY_PATH=/path/to/your/libconfig++.so/:$LD_LIBRARY_PATH
  such as: export LD_LIBRARY_PATH=/usr/local/lib/:$LD_LIBRARY_PATH

  
<h3>User's Documentation:</h3>
<a href="https://loutchau.gitbook.io/raytracer-rayetasoeur/">https://loutchau.gitbook.io/raytracer-rayetasoeur/</a>

<h3>Programmer's Documentation</h3>
See the documentation folder and mostly the documentation/Programmers_manual.pdf
