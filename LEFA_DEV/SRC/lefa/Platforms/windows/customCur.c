/*Open LEFA : Custom Cursor
2023*/

#include"customCur.h";

extern HCURSOR currentCursor;
extern HCURSOR cursor;

// Definição da variável global requestedCursor
static enum CursorType requestedCursor; //Var Cursor

void setCursorType(enum CursorType type) {
    requestedCursor = type;
    switch (type) {
        case CenterArrow:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/AlternateSelect.cur");
            break;
        case Busy:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/Busy.ani");
            break;
        case DiagonalResize1:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/DiagonalResize1.cur");
            break;
        case DiagonalResize2:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/DiagonalResize2.cur");
            break;
        case Handwriting:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/Handwriting.cur");
            break;
        case HelpSelect:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/HelpSelect.cur");
            break;
        case HelpSelect2:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/HelpSelect2.cur");
            break;
        case HorizontalResize:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/HorizontalResize.cur");
            break;
        case LinkSelect:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/LinkSelect.cur");
            break;
        case LinkSelect2:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/LinkSelect2.cur");
            break;
        case Move:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/Move.cur");
            break;
        case Move2:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/Move2.cur");
            break;
        case NormalSelect:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/NormalSelect.cur");
            break;
        case NormalSelect2:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/NormalSelect2.cur");
            break;
        case PrecisionSelect:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/PrecisionSelect.cur");
            break;
        case TextSelect:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/TextSelect.cur");
            break;
        case Unavailable:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/Unavailable.cur");
            break;
        case Unavailable2:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/Unavailable2.cur");
            break;
        case VerticalResize:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/VerticalResize.cur");
            break;
        case WorkingInBackground:
            cursor = LoadCursorFromFile("RES/game/cursor/windows_10x/WorkingInBackground.ani");
            break;
        // Adicione mais casos conforme necessário para outros cursores personalizados
        default:
            cursor = LoadCursor(NULL, IDC_ARROW);
            break;
    }

    currentCursor = cursor;

    SetCursor(cursor);
    //return cursor;
}



/*
void setCursorType(CursorType type) {
    HCURSOR cursor;
    switch (type) {
        case CenterArrow:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/center_ptr.cur");
            break;
        case Cross:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/cross.cur");
            break;
        case CrossHair:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/crosshair.cur");
            break;
        case WidthResise:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/ew-resize.cur");
            break;
        case LeftArrow:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/left_ptr.cur");
            break;
        case LeftMoveArrow:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/move.cur");
            break;
        case NeswResize:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/nesw-resize.cur");
            break;
        case NotAllowed:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/not-allowed.cur");
            break;
        case HeightResise:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/ns-resize.cur");
            break;
        case NwseResize:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/nwse-resize.cur");
            break;
        case PencilCur:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/pencil.cur");
            break;
        case Spooky:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/pirate.cur");
            break;
        case HandCurOpen:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/plus.cur");
            break;
        case HandCurPointer:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/pointer.cur");
            break;
        case ProgressArrow:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/progress.ani");
            break;
        case QuestionArrow:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/question_arrow.ani");
            break;
        case RightArrow:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/right_ptr.cur");
            break;
        case Watch:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/watch.ani");
            break;
        case XtermCur:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/xterm.cur");
            break;
        case ZoomCur:
            cursor = LoadCursorFromFile("RES/game/cursor/comix/zoom-in.cur");
            break;
        // Adicione mais casos conforme necessário para outros cursores personalizados
        default:
            cursor = LoadCursor(NULL, IDC_ARROW);
            break;
    }

    SetCursor(cursor);
}
*/
