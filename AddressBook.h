//---------------------------------------------------------------------------

#ifndef AddressBookH
#define AddressBookH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Gestures.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Colors.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.Header.hpp>
#include "Person.h"
#include "Person.cpp"
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class TAddressBookForm : public TForm
{
__published:	// IDE-managed Components
	TTabControl *Z;
	TTabItem *InsertTab;
	TTabItem *ShowAllTab;
	TTabItem *SearchTab;
	TTabItem *ModifyTab;
	TTabItem *DeleteTab;
	TComboBox *GenderListBox;
	TEdit *NameField;
	TListBoxItem *male;
	TListBoxItem *female;
	TButton *InsertButton;
	TLabel *Header;
	TEdit *PhoneNumberField;
	TEdit *EmailField;
	TComboBox *AgeListBox;
	TListBoxItem *SelectAge;
	TLabel *NameLabel;
	TLabel *PhoneNumberLabel;
	TLabel *EmailLabel;
	TLabel *AgeLabel;
	TLabel *GenderLabel;
	TLabel *StatusLabel;
	TListBoxItem *SelectGender;
	TLabel *CardsLabel;
	TLabel *ShowAllHeader;
	TListBox *Cards;
	TEdit *SearchField;
	TLabel *Label1;
	TLabel *Label3;
	TListBox *MatchingCards;
	TLabel *MatchingCardsLabel;
	TButton *SearchButton;
	TGroupBox *ModificationField;
	TLabel *Label2;
	TComboBox *ModificationCardListBox;
	TListBoxItem *ListBoxItem1;
	TEdit *PhoneNumberModificationField;
	TEdit *EmailModificationField;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TComboBox *AgeModificationList;
	TButton *ModifyButton;
	TLabel *Label7;
	TComboBox *GenderModificationList;
	TListBoxItem *Agelist1;
	TListBoxItem *ListBoxItem2;
	TListBoxItem *ListBoxItem3;
	TListBoxItem *ListBoxItem4;
	TLabel *ModificationStatusLabel;
	TLabel *Label8;
	TComboBox *DeletionCardListBox;
	TListBoxItem *DeletionCardListItem1;
	TButton *DeleteButton;
	TLabel *DeletionLabel;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall InsertButtonClick(TObject *Sender);
	void __fastcall ShowAllTabClick(TObject *Sender);
	void __fastcall SearchButtonClick(TObject *Sender);
	void __fastcall ModifyTabClick(TObject *Sender);
	void __fastcall DeleteTabClick(TObject *Sender);
	void __fastcall DeleteButtonClick(TObject *Sender);
	void __fastcall ModifyButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAddressBookForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddressBookForm *AddressBookForm;
//---------------------------------------------------------------------------
#endif
