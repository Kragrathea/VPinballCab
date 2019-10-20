#ifndef H_TOOLBAR_DIALOG
#define H_TOOLBAR_DIALOG

class ToolbarDialog : public CDialog
{
public:
    ToolbarDialog();
    virtual ~ToolbarDialog();

protected:
    virtual BOOL OnInitDialog();
    virtual void OnDestroy();
    virtual INT_PTR DialogProc(UINT msg, WPARAM wparam, LPARAM lparam);
    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

private:
    enum LAYER_INDICES
    {
        LAYER1 = 0,
        LAYER2 = 1,
        LAYER3 = 2,
        LAYER4 = 3,
        LAYER5 = 4,
        LAYER6 = 5,
        LAYER7 = 6,
        LAYER8 = 7,
        LAYER9 = 8,
        LAYER10 = 9,
        LAYER11 = 10,
        TOGGLE_ALL = 11
    };

    HWND m_hwnd;
    CResizer m_resizer;
    CButton m_magnifyButton;
    CButton m_selectButton;
    CButton m_optionsButton;
    CButton m_scriptButton;
    CButton m_backglassButton;
    CButton m_playButton;
    CButton m_layerButtons[12];
    CButton m_wallButton;
    CButton m_gateButton;
    CButton m_rampButton;
    CButton m_flipperButton;
    CButton m_plungerButton;
    CButton m_bumperButton;
    CButton m_spinnerButton;
    CButton m_timerButton;
    CButton m_triggerButton;
    CButton m_lightButton;
    CButton m_kickerButton;
    CButton m_targetButton;
    CButton m_decalButton;
    CButton m_textboxButton;
    CButton m_reelButton;
    CButton m_lightseqButton;
    CButton m_primitiveButton;
    CButton m_flasherButton;
    CButton m_rubberButton;
};

#endif H_TOOLBAR_DIALOG