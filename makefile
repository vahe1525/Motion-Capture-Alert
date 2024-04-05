main:  cpp_target csharp_target

cpp_target:
	g++ -std=c++11 \
		Data/Constants.hpp \
		Exceptions/Exception.hpp \
		CameraFiles/Pixel.hpp \
	    	CameraFiles/Matrix.hpp \
		CameraFiles/Webcam.cpp \
		CameraFiles/BMPExporter.hpp \
		Algorithms/DifferenceOfColors.hpp \
		Algorithms/CameraFilesChecker.hpp \
		Algorithms/Comparer.hpp \
		Algorithms/Capturer.hpp \
		Manager.hpp \
		Main.cpp \
		-lpthread \
		-o Capture

csharp_target:
	dotnet build
