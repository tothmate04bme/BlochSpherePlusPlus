include(/home/tm8/Qt/Examples/Qt-6.8.0/quick3d/hellocube/build/Desktop_Qt_6_8_0-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/hellocube-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative;qtdeclarative")

qt6_deploy_qml_imports(TARGET hellocube PLUGINS_FOUND plugins_found)
qt6_deploy_runtime_dependencies(
    EXECUTABLE /home/tm8/Qt/Examples/Qt-6.8.0/quick3d/hellocube/build/Desktop_Qt_6_8_0-Debug/hellocube
    ADDITIONAL_MODULES ${plugins_found}
    GENERATE_QT_CONF
)