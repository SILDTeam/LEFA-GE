#ifndef CUSTOMCUR_H
#define CUSTOMCUR_H
#include<windows.h>


//void setDefaultCursor();


enum CursorType {
    CenterArrow,
    Busy,
    DiagonalResize1,
    DiagonalResize2,
    Handwriting,
    HelpSelect,
    HelpSelect2,
    HorizontalResize,
    LinkSelect,
    LinkSelect2,
    Move,
    Move2,
    NormalSelect,
    NormalSelect2,
    PrecisionSelect,
    TextSelect,
    Unavailable,
    Unavailable2,
    VerticalResize,
    WorkingInBackground,

    // Adicione mais tipos de cursores personalizados aqui, se necessário
}; 


void setCursorType(CursorType type);

/*
enum CursorType {
	CenterArrow,
	Cross,
	CrossHair,
	WidthResise,
    LeftArrow,
    LeftMoveArrow,
    NeswResize,
    NotAllowed,
    HeightResise,
    NwseResize,
    PencilCur,
    Spooky,
    HandCurOpen,
    HandCurPointer,
    ProgressArrow,
    QuestionArrow,
    RightArrow,
    Watch,
    XtermCur,
    ZoomCur,

    // Adicione mais tipos de cursores personalizados aqui, se necessário
};
*/


#endif //CUSTOMCUR_H