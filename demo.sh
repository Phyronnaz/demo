cd Raytracing-demo
make && ./main

cd ../Raytracing-Demo_shadows_overlapping
make && ./main

cd ../Raytracing-demo_specular
make && ./main

cd ../Raytracing-reflex
make && ./main

cd ../Raytracing-cubes
make && ./main

cd ../Raytracing-floor
make && ./main

cd ../Raytracing_final_demo
doxygen Doxyfile
make && ./main
