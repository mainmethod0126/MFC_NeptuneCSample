// PopupStrobeDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NeptuneCSample.h"
#include "PopupStrobeDlg.h"
#include "afxdialogex.h"


// CPopupStrobeDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPopupStrobeDlg, CPopupBaseDialog)

CPopupStrobeDlg::CPopupStrobeDlg(NeptuneCamHandle& pCameraHandle, CWnd** ppThis)
	: CPopupBaseDialog(CPopupStrobeDlg::IDD, pCameraHandle, ppThis)
	, m_bStrobeEnable(FALSE)
	, m_nlStrobeDelay(0)
	, m_nlStrobeDuration(0)
	, m_strDelayRange(_T(""))
	, m_strDurationRange(_T(""))
{
}

CPopupStrobeDlg::~CPopupStrobeDlg()
{
}

void CPopupStrobeDlg::DoDataExchange(CDataExchange* pDX)
{
	CPopupBaseDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_ENABLE, m_bStrobeEnable);
	DDX_Control(pDX, IDC_COMBO_MODE, m_cbStrobeMode);
	DDX_Control(pDX, IDC_COMBO_POLARITY, m_cbStrobePolarity);
	DDX_Text(pDX, IDC_EDIT_DELAY, m_nlStrobeDelay);
	DDX_Text(pDX, IDC_EDIT_DURATION, m_nlStrobeDuration);
	DDX_Text(pDX, IDC_STATIC_DELAY_RANGE, m_strDelayRange);
	DDX_Text(pDX, IDC_STATIC_DURATION_RANGE, m_strDurationRange);
}


BEGIN_MESSAGE_MAP(CPopupStrobeDlg, CPopupBaseDialog)
	ON_BN_CLICKED(IDC_BUTTON_APPLY, &CPopupStrobeDlg::OnBnClickedButtonApply)
END_MESSAGE_MAP()

void CPopupStrobeDlg::UpdateDialog()
{
	m_bStrobeEnable = FALSE;
	m_cbStrobeMode.ResetContent();
	m_cbStrobePolarity.ResetContent();
	m_nlStrobeDelay = 0;
	m_nlStrobeDuration = 0;
	m_strDelayRange = _T("(Min ~ Max)");
	m_strDurationRange = _T("(Min ~ Max)");

	if (m_pCameraHandle)
	{
		NEPTUNE_STROBE_INFO stStrobeInfo;
		ENeptuneError emErr = ntcGetStrobeInfo(m_pCameraHandle, &stStrobeInfo);
		if (emErr == NEPTUNE_ERR_Success)
		{
			if (stStrobeInfo.bSupport == NEPTUNE_BOOL_TRUE)
			{
				CString strItem = _T("");
				int nItem = CB_ERR;
				int nFlag = (int)stStrobeInfo.nStrobeFlag;
				for (int i = 0; i < 31; i++)
				{
					if ((nFlag & 0x01) == 0x01)
					{
						strItem.Format(_T("Timer%d"), i);
						nItem = m_cbStrobeMode.InsertString(m_cbStrobeMode.GetCount(), strItem);
						m_cbStrobeMode.SetItemData(nItem, i);
					}
					nFlag = (nFlag >> 1);
				}

				if (((stStrobeInfo.nPolarityFlag >> NEPTUNE_POLARITY_RISINGEDGE) & 0x01) == 0x01)
				{
					nItem = m_cbStrobePolarity.InsertString(m_cbStrobePolarity.GetCount(), _T("Rising Edge"));
					m_cbStrobePolarity.SetItemData(nItem, NEPTUNE_POLARITY_RISINGEDGE);
				}
				if (((stStrobeInfo.nPolarityFlag >> NEPTUNE_POLARITY_FALLINGEDGE) & 0x01) == 0x01)
				{
					nItem = m_cbStrobePolarity.InsertString(m_cbStrobePolarity.GetCount(), _T("Falling Edge"));
					m_cbStrobePolarity.SetItemData(nItem, NEPTUNE_POLARITY_FALLINGEDGE);
				}
				if (((stStrobeInfo.nPolarityFlag >> NEPTUNE_POLARITY_ANYEDGE) & 0x01) == 0x01)
				{
					nItem = m_cbStrobePolarity.InsertString(m_cbStrobePolarity.GetCount(), _T("Any Edge"));
					m_cbStrobePolarity.SetItemData(nItem, NEPTUNE_POLARITY_ANYEDGE);
				}
				if (((stStrobeInfo.nPolarityFlag >> NEPTUNE_POLARITY_LEVELHIGH) & 0x01) == 0x01)
				{
					nItem = m_cbStrobePolarity.InsertString(m_cbStrobePolarity.GetCount(), _T("High Level"));
					m_cbStrobePolarity.SetItemData(nItem, NEPTUNE_POLARITY_LEVELHIGH);
				}
				if (((stStrobeInfo.nPolarityFlag >> NEPTUNE_POLARITY_LEVELLOW) & 0x01) == 0x01)
				{
					nItem = m_cbStrobePolarity.InsertString(m_cbStrobePolarity.GetCount(), _T("Low Level"));
					m_cbStrobePolarity.SetItemData(nItem, NEPTUNE_POLARITY_LEVELLOW);
				}

				m_strDelayRange.Format(_T("(%d ~ %d)"), stStrobeInfo.nDelayMin, stStrobeInfo.nDelayMax);
				m_strDurationRange.Format(_T("(%d ~ %d)"), stStrobeInfo.nDurationMin, stStrobeInfo.nDurationMax);

				NEPTUNE_STROBE stStrobe;
				emErr = ntcGetStrobe(m_pCameraHandle, &stStrobe);
				if (emErr == NEPTUNE_ERR_Success)
				{
					m_bStrobeEnable = (stStrobe.OnOff == NEPTUNE_BOOL_TRUE);

					for (int i = 0; i < m_cbStrobeMode.GetCount(); i++)
					{
						if (stStrobe.Strobe == (ENeptuneStrobe)m_cbStrobeMode.GetItemData(i))
						{
							m_cbStrobeMode.SetCurSel(i);
							break;
						}
					}

					for (int i = 0; i < m_cbStrobePolarity.GetCount(); i++)
					{
						if (stStrobe.Polarity == (ENeptunePolarity)m_cbStrobePolarity.GetItemData(i))
						{
							m_cbStrobePolarity.SetCurSel(i);
							break;
						}
					}

					m_nlStrobeDelay = stStrobe.nDelay;
					m_nlStrobeDuration = stStrobe.nDuration;
				}
				else
				{
					InsertLog(TYPE_ERROR, _T("ntcGetStrobe Failed."), emErr);
				}
			}
		}
		else
		{
			InsertLog(TYPE_ERROR, _T("ntcGetStrobeInfo Failed."), emErr);
		}
	}
	UpdateData(FALSE);
}

void CPopupStrobeDlg::OnBnClickedButtonApply()
{
	UpdateData(TRUE);
	if (m_pCameraHandle)
	{
		NEPTUNE_STROBE stStrobe;
		stStrobe.OnOff = m_bStrobeEnable ? NEPTUNE_BOOL_TRUE : NEPTUNE_BOOL_FALSE;
		stStrobe.Strobe = (ENeptuneStrobe)m_cbStrobeMode.GetItemData(m_cbStrobeMode.GetCurSel());
		stStrobe.Polarity = (ENeptunePolarity)m_cbStrobePolarity.GetItemData(m_cbStrobePolarity.GetCurSel());
		stStrobe.nDelay = (_uint16_t)m_nlStrobeDelay;
		stStrobe.nDuration = (_uint16_t)m_nlStrobeDuration;
		ENeptuneError emErr = ntcSetStrobe(m_pCameraHandle, stStrobe);
		if (emErr != NEPTUNE_ERR_Success)
		{
			UpdateDialog();
			InsertLog(TYPE_ERROR, _T("ntcSetStrobe Failed."), emErr);
		}
	}
}