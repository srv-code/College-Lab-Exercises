using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;

public partial class WizardControlTest : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
		if (!Page.IsPostBack)
			Wizard1.ActiveStepIndex = 0;
    }

	protected void Wizard1_NextButtonClick(object sender, WizardNavigationEventArgs e) {
		if(Wizard1.ActiveStepIndex==0) {
			if(RadioButtonSkip.Checked) {
				Debug.Print("skipping step 1");
 				Wizard1.ActiveStepIndex = 2;
			}
		}
	}
}