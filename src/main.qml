import QtQuick
import QtQuick3D
import QtQuick3D.Helpers
import QtQuick.Layouts
import QtQuick.Controls

Window {
    id: root
    width: 640
    height: 640
    visible: true
    color: "black"

    /*ColumnLayout{
        id: layout

    Button{
        text: "Button"
        onClicked: myView.doSomething("Works")
        //onClicked: console.log('click works')
    }*/

    View3D {
        id: blochSphereView
        anchors.fill: parent

        environment: SceneEnvironment {
            clearColor: "gray"
            backgroundMode: SceneEnvironment.Color
        }

        Node{
            id: cameraNode

            PerspectiveCamera {
                id: sceneCamera
                position: Qt.vector3d(0, 0, 150)
                //eulerRotation.x: -30
            }
        }

        OrbitCameraController {
               anchors.fill: parent
               origin: cameraNode
               camera: sceneCamera
           }

        DirectionalLight {
            ambientColor: Qt.rgba(1.0, 1.0, 1.0, 1.0)  // white ambient light
            //intensity: 0.5  // adjust the intensity for your desired effect
        }

        //The bloch sphere
        Model {
            position: Qt.vector3d(0, 0, 0)
            source: "#Sphere"
            scale: Qt.vector3d(1, 1, 1)
            materials: [
                    DefaultMaterial {
                        diffuseColor: "#FFFFFF"
                        opacity: 0.5
                        blendMode: DefaultMaterial.SourceOver
                    }
            ]
        }

        //A tengelyek eddig egy kicsit zavarosak. A blosh-gömb
        //és az opengl más sorrendek használ, majd még kitalálom,
        //hogy melyik-melyik.

        //Z axis

        Model {
            position: Qt.vector3d(0, 0, 0)
            source: "#Cylinder"
            scale: Qt.vector3d(0.03, 0.9, 0.03)
            materials: [ DefaultMaterial {
            diffuseColor: "blue"
                }
            ]
        }

        Model {
            position: Qt.vector3d(0, 39, 0)
            source: "#Cone"
            scale: Qt.vector3d(0.1, 0.1, 0.1)
            materials: [ DefaultMaterial {
            diffuseColor: "blue"
                }
            ]
        }

        //Y axis

        Model {
            position: Qt.vector3d(0, 0, 0)
            source: "#Cylinder"
            scale: Qt.vector3d(0.03, 0.9, 0.03)
            eulerRotation: Qt.vector3d(90, 0, 0)
            materials: [ DefaultMaterial {
            diffuseColor: "red"
                }
            ]
        }

        Model {
            position: Qt.vector3d(0, 0, -39)
            source: "#Cone"
            scale: Qt.vector3d(0.1, 0.1, 0.1)
            eulerRotation: Qt.vector3d(-90, 0, 0)
            materials: [ DefaultMaterial {
            diffuseColor: "red"
                }
            ]
        }

        //Z Axis

        Model {
            position: Qt.vector3d(0, 0, 0)
            source: "#Cylinder"
            scale: Qt.vector3d(0.03, 0.9, 0.03)
            eulerRotation: Qt.vector3d(0, 0, 90)
            materials: [ DefaultMaterial {
            diffuseColor: "green"
                }
            ]
        }

        Model {
            position: Qt.vector3d(39, 0, 0)
            source: "#Cone"
            scale: Qt.vector3d(0.1, 0.1, 0.1)
            eulerRotation: Qt.vector3d(0, 0, -90)
            materials: [ DefaultMaterial {
            diffuseColor: "green"
                }
            ]
        }

        //A valószínűségi amplitúdó vektora

        Model {
            id: amplitude
            position: Qt.vector3d(0, 20, 0)
            source: "#Cylinder"
            scale: Qt.vector3d(0.03, 0.45, 0.03)
            eulerRotation: Qt.vector3d(0, 0, 0)
            materials: [ DefaultMaterial {
            diffuseColor: "black"
                }
            ]
        }

    }

    //}

}
