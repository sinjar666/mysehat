# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

symbian:TARGET.UID3 = 0xE7BEECEA

# Smart Installer package's UID
# This UID is from the protected range 
# and therefore the package will fail to install if self-signed
# By default qmake uses the unprotected range value if unprotected UID is defined for the application
# and 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
# CONFIG += mobility
# MOBILITY +=

QT+=xml core gui

maemo5  {
CONFIG += link_pkgconfig
PKGCONFIG += gtk+-2.0 \
            gstreamer-0.10 \
            gstreamer-plugins-bad-0.10 \
            gdigicam-0.3 \
            gdigicam-gst-camerabin-0.3
QT += dbus

}

DEFINES += QT_NO_DEBUG_OUTPUT QT_NO_WARNING_OUTPUT QT_NO_DEBUG_STREAM

SOURCES += main.cpp \
    search-engine/searchwidget.cpp \
    search-engine/linkdiseasedialog.cpp \
    search-engine/itemlist.cpp \
    search-engine/itembutton.cpp \
    search-engine/dialogright.cpp \
    search-engine/addnewdisease.cpp \
    search-engine/engine/indexitem.cpp \
    search-engine/engine/engine.cpp \
    search-engine/xdisease/xdisease.cpp \
    search-engine/widgets/typedatewid.cpp \
    search-engine/widgets/rwid.cpp \
    search-engine/widgets/itemwidget.cpp \
    search-engine/widgets/filterdialog.cpp \
    mainwidget.cpp \
    filecreationerr.cpp \
    fatalnotavail.cpp \
    fatalmessage.cpp \
    errorfiledialog.cpp \
    configdialog.cpp \
    config/config.cpp \
    newuserdialog.cpp \
    userlistdialog.cpp \
    adddetails/additemwidget.cpp \
    adddetails/additembutton.cpp \
    model/vaccine.cpp \
    model/symptom.cpp \
    model/surgery.cpp \
    model/investigation.cpp \
    model/familyhistory.cpp \
    model/drug.cpp \
    model/appointment.cpp \
    model/allergen.cpp \
    ui/Vaccine/add/vaccinedetailswid.cpp \
    ui/Vaccine/add/vaccinebottomwid.cpp \
    ui/Vaccine/add/addvaccinewid.cpp \
    xml/Vaccine/xvaccine.cpp \
    IdGen/idgen.cpp \
    KeyFinder/keyfinder.cpp \
    ui/Allergen/add/upper.cpp \
    ui/Allergen/add/middle.cpp \
    ui/Allergen/add/bottom.cpp \
    ui/Allergen/add/addallergenwid.cpp \
    xml/Allergen/xallergen.cpp \
    ui/Investigation/add/addinvestigationwid.cpp \
    ui/Appointment/add/appointmentnamewid.cpp \
    ui/Appointment/add/appointmentlinkwid.cpp \
    ui/Appointment/add/appointmentdatetimewid.cpp \
    ui/Appointment/add/appointmentbottombar.cpp \
    ui/Appointment/add/addappointmentwid.cpp \
    ui/Drug/add/adddrugwid.cpp \
    ui/FamilyHistory/add/addfamilyhistorywid.cpp \
    ui/Surgery/add/addsurgerywid.cpp \
    ui/Symptom/add/addsymptomwid.cpp \
    xml/Appointment/xappointment.cpp \
    xml/Drug/xdrug.cpp \
    xml/FamilyHistory/xfamilyhistory.cpp \
    xml/Investigation/xinvestigation.cpp \
    xml/Surgery/xsurgery.cpp \
    xml/Symptom/xsymptom.cpp \
    stillcam/stillcam.cpp \
    appointmentbutton.cpp \
    appointmentlist.cpp \
    ui/Appointment/display/displayappointmentwid.cpp \
    ui/Allergen/display/displayallergenwid.cpp \
    ui/FamilyHistory/display/displayfamilyhistorywid.cpp \
    ui/Investigation/display/displayinvestigationwid.cpp \
    ui/Surgery/display/displaysurgerywid.cpp \
    ui/Symptom/display/displaysymptomwid.cpp \
    ui/Vaccine/display/displayvaccinewid.cpp \
    ui/Drug/display/displaydrugwid.cpp \
    ui/ShowItemsDialog/showitemsdialog.cpp \
    ui/SearchDialog/searchdialog.cpp \
    ui/Allergen/edit/editallergenwid.cpp \
    ui/Appointment/edit/editlinksdialog.cpp \
    ui/Appointment/edit/editappointmentwid.cpp \
    ui/Drug/edit/editdrugwid.cpp \
    ui/FamilyHistory/edit/editfamilyhistorywid.cpp \
    ui/Investigation/edit/editinvestigationwid.cpp \
    ui/Surgery/edit/editsurgerywid.cpp \
    ui/Symptom/edit/editsymptomwid.cpp \
    ui/Vaccine/edit/editvaccinewid.cpp \
    ui/Allergen/edit/editbottom.cpp \
    ui/Allergen/edit/editmiddle.cpp \
    ui/Allergen/edit/editupper.cpp \
    deletewid.cpp \
    about/aboutdialog.cpp \
    passman/passman.cpp \
    passdialog.cpp \
    passdialoginfo.cpp \
    changepasswid.cpp \
    ui/Investigation/display/displayreportsdialog.cpp
HEADERS += \
    search-engine/searchwidget.h \
    search-engine/linkdiseasedialog.h \
    search-engine/itemlist.h \
    search-engine/itembutton.h \
    search-engine/dialogright.h \
    search-engine/addnewdisease.h \
    search-engine/engine/indexitem.h \
    search-engine/engine/engine.h \
    search-engine/xdisease/xdisease.h \
    search-engine/widgets/typedatewid.h \
    search-engine/widgets/rwid.h \
    search-engine/widgets/itemwidget.h \
    search-engine/widgets/filterdialog.h \
    mainwidget.h \
    filecreationerr.h \
    fatalnotavail.h \
    fatalmessage.h \
    errorfiledialog.h \
    configdialog.h \
    config/config.h \
    newuserdialog.h \
    userlistdialog.h \
    adddetails/additemwidget.h \
    adddetails/additembutton.h \
    model/vaccine.h \
    model/symptom.h \
    model/surgery.h \
    model/investigation.h \
    model/familyhistory.h \
    model/drug.h \
    model/appointment.h \
    model/allergen.h \
    ui/Vaccine/add/vaccinedetailswid.h \
    ui/Vaccine/add/vaccinebottomwid.h \
    ui/Vaccine/add/addvaccinewid.h \
    xml/Vaccine/xvaccine.h \
    IdGen/idgen.h \
    KeyFinder/keyfinder.h \
    ui/Allergen/add/addallergenwid.h \
    xml/Allergen/xallergen.h \
    ui/Investigation/add/addinvestigationwid.h \
    ui/Appointment/add/appointmentnamewid.h \
    ui/Appointment/add/appointmentlinkwid.h \
    ui/Appointment/add/appointmentdatetimewid.h \
    ui/Appointment/add/appointmentbottombar.h \
    ui/Appointment/add/addappointmentwid.h \
    ui/Drug/add/adddrugwid.h \
    ui/FamilyHistory/add/addfamilyhistorywid.h \
    ui/Surgery/add/addsurgerywid.h \
    ui/Symptom/add/addsymptomwid.h \
    xml/Appointment/xappointment.h \
    xml/Drug/xdrug.h \
    xml/FamilyHistory/xfamilyhistory.h \
    xml/Investigation/xinvestigation.h \
    xml/Surgery/xsurgery.h \
    xml/Symptom/xsymptom.h \
    stillcam/stillcam.h \
    appointmentbutton.h \
    appointmentlist.h \
    ui/Appointment/display/displayappointmentwid.h \
    ui/Allergen/display/displayallergenwid.h \
    ui/FamilyHistory/display/displayfamilyhistorywid.h \
    ui/Investigation/display/displayinvestigationwid.h \
    ui/Surgery/display/displaysurgerywid.h \
    ui/Symptom/display/displaysymptomwid.h \
    ui/Vaccine/display/displayvaccinewid.h \
    ui/Drug/display/displaydrugwid.h \
    ui/ShowItemsDialog/showitemsdialog.h \
    ui/SearchDialog/searchdialog.h \
    ui/Allergen/edit/editallergenwid.h \
    ui/Appointment/edit/editlinksdialog.h \
    ui/Appointment/edit/editappointmentwid.h \
    ui/Drug/edit/editdrugwid.h \
    ui/FamilyHistory/edit/editfamilyhistorywid.h \
    ui/Investigation/edit/editinvestigationwid.h \
    ui/Surgery/edit/editsurgerywid.h \
    ui/Symptom/edit/editsymptomwid.h \
    ui/Vaccine/edit/editvaccinewid.h \
    ui/Allergen/add/bottom.h \
    ui/Allergen/add/middle.h \
    ui/Allergen/add/upper.h \
    ui/Allergen/edit/editbottom.h \
    ui/Allergen/edit/editmiddle.h \
    ui/Allergen/edit/editupper.h \
    deletewid.h \
    about/aboutdialog.h \
    passman/passman.h \
    passdialog.h \
    passdialoginfo.h \
    changepasswid.h \
    ui/Investigation/display/displayreportsdialog.h
FORMS += mainwindow.ui

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()

OTHER_FILES += \
    qtc_packaging/debian_fremantle/rules \
    qtc_packaging/debian_fremantle/README \
    qtc_packaging/debian_fremantle/copyright \
    qtc_packaging/debian_fremantle/control \
    qtc_packaging/debian_fremantle/compat \
    qtc_packaging/debian_fremantle/changelog \
    search-engine/icons/symptom.jpg \
    search-engine/icons/surgery.jpg \
    search-engine/icons/Search.png \
    search-engine/icons/misc.jpg \
    search-engine/icons/investigation.jpg \
    search-engine/icons/family.jpg \
    search-engine/icons/drug.jpg \
    search-engine/icons/blood-test.jpg \
    search-engine/icons/allergen.jpg \
    search-engine/icons/vaccine.xpm \
    search-engine/icons/symptom.xpm \
    search-engine/icons/surgery.xpm \
    search-engine/icons/misc.xpm \
    search-engine/icons/investigation.xpm \
    search-engine/icons/family.xpm \
    search-engine/icons/drug.xpm \
    search-engine/icons/allergen.xpm

RESOURCES += \
    resources.qrc
