#pragma once

#include "quickVtkImageAlgorithm.hpp"

#include <vtkImageReader2.h>

namespace quick {

    namespace Vtk {

        class ImageReader2 : public ImageAlgorithm {
            Q_OBJECT
            Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged);
        private:
            static Qml::Register::Symbol::AbstractClass<ImageReader2> Register;
            vtkSmartPointer<vtkImageReader2> m_vtkObject;
            QString m_fileName;
        public:
            ImageReader2(vtkSmartPointer<vtkImageReader2>);
            auto setFileName(QString&) -> void;
            auto getFileName() -> QString;
            virtual auto isValid() -> bool;
        signals:
            void fileNameChanged();
        };
    }
}
