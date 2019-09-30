<%@ Page Language="C#" AutoEventWireup="true" CodeFile="WizardControlTest.aspx.cs" Inherits="WizardControlTest" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>[Test] WizardControlTest</title>
</head>
<body>
    <form id="form1" runat="server">
		<div>
			<asp:Wizard ID="Wizard1" runat="server" ActiveStepIndex="0" 
				onnextbuttonclick="Wizard1_NextButtonClick">
				<WizardSteps>
					<asp:WizardStep ID="WizardStep1" runat="server" Title="Step 1" StepType="Start">
						<h2>Step 1</h2>
						<asp:RadioButton ID="RadioButtonSkip" runat="server" Text="Skip step 2" GroupName="skip" /> <br>
						<asp:RadioButton ID="RadioButtonDontSkip" runat="server" Text="Dont skip step 2" GroupName="skip" />
					</asp:WizardStep>
					<asp:WizardStep ID="WizardStep2" runat="server" Title="Step 2" StepType="Step">
						<h2>Step 2</h2>
					</asp:WizardStep>
					<asp:WizardStep ID="WizardStep3" runat="server" Title="Complete" StepType="Finish">
						<h2>Complete</h2>
					</asp:WizardStep>
				</WizardSteps>
			</asp:Wizard>
		</div>
    </form>
</body>
</html>
