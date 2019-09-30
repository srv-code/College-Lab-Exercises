<%@ Page Language="C#" AutoEventWireup="true" CodeFile="RegistrationForm.aspx.cs" Inherits="Registration" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Students Placements Registration</title>
	<link rel="stylesheet" type="text/css" href="~/Styles/custom.css" />
</head>
<body>
    <form id="form1" runat="server">
        <div class="header">Registration Form</div>
        <div>
            <asp:HyperLink ID="HyperLink1" runat="server" 
                NavigateUrl="~/RegistrationData.aspx">View registration data</asp:HyperLink>
        </div>
		<div>
			<asp:Wizard ID="Wizard_Registration" runat="server"
                CssClass="form"
                CancelDestinationPageUrl="~/Cancelled.aspx"
				ActiveStepIndex="0"
				HeaderText="Profile Registration"				
				DisplayCancelButton="True" 
				onfinishbuttonclick="Wizard_Registration_FinishButtonClick" 
                DisplaySideBar="False">
				<WizardSteps>
					<asp:WizardStep ID="WizardStep_PersonalInformation" runat="server"
						Title="Personal Information" 
						AllowReturn="False"
						StepType="Start">
						<table>
							<tr>
								<td>Name</td>
								<td>
									<asp:TextBox ID="TextBox_Name" runat="server"></asp:TextBox>
								</td>
							<tr>
								<td>
									Gender</td>
								<td>
									<asp:RadioButtonList ID="RadioButtonList_Gender" runat="server" 
										RepeatDirection="Horizontal">
										<asp:ListItem Value="M">Male</asp:ListItem>
										<asp:ListItem Value="F">Female</asp:ListItem>
										<asp:ListItem Value="T">Transgender</asp:ListItem>
									</asp:RadioButtonList>
								</td>
							</tr>
							<tr>
								<td>
									Date of Birth</td>
								<td>
									<asp:TextBox ID="TextBox_DOB" runat="server" ReadOnly="True"></asp:TextBox>
									<asp:LinkButton ID="LinkButton_ShowCalendar" runat="server" 
										OnClick="LinkButton_ShowCalendar_Click">set</asp:LinkButton>
									<asp:Calendar ID="Calendar_DOB" runat="server" Visible="False" 
										OnSelectionChanged="Calendar_DOB_SelectionChanged" BackColor="White" BorderColor="#3366CC" 
										BorderWidth="1px" CellPadding="1" DayNameFormat="Shortest" Font-Names="Verdana" 
										Font-Size="8pt" ForeColor="#003399" Height="200px" Width="220px">
										<DayHeaderStyle BackColor="#99CCCC" ForeColor="#336666" Height="1px" />
										<NextPrevStyle Font-Size="8pt" ForeColor="#CCCCFF" />
										<OtherMonthDayStyle ForeColor="#999999" />
										<SelectedDayStyle BackColor="#009999" Font-Bold="True" ForeColor="#CCFF99" />
										<SelectorStyle BackColor="#99CCCC" ForeColor="#336666" />
										<TitleStyle BackColor="#003399" BorderColor="#3366CC" BorderWidth="1px" 
											Font-Bold="True" Font-Size="10pt" ForeColor="#CCCCFF" Height="25px" />
										<TodayDayStyle BackColor="#99CCCC" ForeColor="White" />
										<WeekendDayStyle BackColor="#CCCCFF" />
									</asp:Calendar>
								</td>
							</tr>
							<tr>
								<td>
									Address</td>
								<td>
									<asp:TextBox ID="TextBox_Address" TextMode="MultiLine" runat="server"></asp:TextBox>
								</td>
							</tr>
						</table>
					</asp:WizardStep>
					<asp:WizardStep ID="WizardStep_AcademicInformation" runat="server" 
						Title="Academic Information" 
						AllowReturn="False" 
						StepType="Step">
						<table>
							<tr>
								<td>10th</td>
								<td>
									<asp:TextBox ID="TextBox_Marks10th" runat="server"></asp:TextBox>
								</td>
							</tr>
							<tr>
								<td>12th</td>
								<td>
									<asp:TextBox ID="TextBox_Marks12th" runat="server"></asp:TextBox>
								</td>
							</tr>
							<tr>
								<td>UG Grade</td>
								<td>
									<asp:TextBox ID="TextBox_GradeUG" runat="server"></asp:TextBox>
								</td>
							</tr>
							<tr>
								<td>PG Grade</td>
								<td><asp:TextBox ID="TextBox_GradePG" runat="server"></asp:TextBox></td>
							</tr>
						</table>
					</asp:WizardStep>
					<asp:WizardStep ID="WizardStep_OtherInformation" runat="server" 
						Title="Others" 
						AllowReturn="False" 
						StepType="Finish">
						<table>
							<tr>
								<td>Achievements</td>
								<td>
									<asp:TextBox ID="TextBox_Achievements" runat="server" TextMode="MultiLine"></asp:TextBox>
								</td>
							</tr>
							<tr>
								<td>Reference 1</td>
								<td><asp:TextBox ID="TextBox_Reference1" TextMode="MultiLine" runat="server"></asp:TextBox></td>
							</tr>
							<tr>
								<td>Reference 2</td>
								<td><asp:TextBox ID="TextBox_Reference2" TextMode="MultiLine" runat="server"></asp:TextBox></td>								
							</tr>
							<tr>
								<td>Reference 3</td>
								<td><asp:TextBox ID="TextBox_Reference3" TextMode="MultiLine" runat="server"></asp:TextBox></td>
							</tr>							
						</table>
					</asp:WizardStep>
					<asp:WizardStep ID="WizardStep_Submitted" runat="server" 
						Title="Submitted"
						AllowReturn="False" 
						StepType="Complete">
						<div><asp:Label ID="Label_InsertionStatus" runat="server"></asp:Label></div>
					</asp:WizardStep>
				</WizardSteps>
			</asp:Wizard>
		</div>

		<!-- Data source -->
    	<asp:SqlDataSource ID="SqlDataSource_Student" runat="server" 
			ConnectionString="<%$ ConnectionStrings:constr_locdb %>" 
			SelectCommand="SELECT * FROM [students]" ConflictDetection="CompareAllValues" 
			DeleteCommand="DELETE FROM [students] WHERE [id] = @original_id AND [name] = @original_name AND (([gender] = @original_gender) OR ([gender] IS NULL AND @original_gender IS NULL)) AND (([dob] = @original_dob) OR ([dob] IS NULL AND @original_dob IS NULL)) AND (([address] = @original_address) OR ([address] IS NULL AND @original_address IS NULL)) AND (([marks_10] = @original_marks_10) OR ([marks_10] IS NULL AND @original_marks_10 IS NULL)) AND (([marks_12] = @original_marks_12) OR ([marks_12] IS NULL AND @original_marks_12 IS NULL)) AND (([grade_ug] = @original_grade_ug) OR ([grade_ug] IS NULL AND @original_grade_ug IS NULL)) AND (([grade_pg] = @original_grade_pg) OR ([grade_pg] IS NULL AND @original_grade_pg IS NULL)) AND (([achievement] = @original_achievement) OR ([achievement] IS NULL AND @original_achievement IS NULL)) AND (([reference1] = @original_reference1) OR ([reference1] IS NULL AND @original_reference1 IS NULL)) AND (([reference2] = @original_reference2) OR ([reference2] IS NULL AND @original_reference2 IS NULL)) AND (([reference3] = @original_reference3) OR ([reference3] IS NULL AND @original_reference3 IS NULL))" 
			InsertCommand="INSERT INTO [students] ([name], [gender], [dob], [address], [marks_10], [marks_12], [grade_ug], [grade_pg], [achievement], [reference1], [reference2], [reference3]) VALUES (@name, @gender, @dob, @address, @marks_10, @marks_12, @grade_ug, @grade_pg, @achievement, @reference1, @reference2, @reference3)" 
			OldValuesParameterFormatString="original_{0}" 
			
            
			UpdateCommand="UPDATE [students] SET [name] = @name, [gender] = @gender, [dob] = @dob, [address] = @address, [marks_10] = @marks_10, [marks_12] = @marks_12, [grade_ug] = @grade_ug, [grade_pg] = @grade_pg, [achievement] = @achievement, [reference1] = @reference1, [reference2] = @reference2, [reference3] = @reference3 WHERE [id] = @original_id AND [name] = @original_name AND (([gender] = @original_gender) OR ([gender] IS NULL AND @original_gender IS NULL)) AND (([dob] = @original_dob) OR ([dob] IS NULL AND @original_dob IS NULL)) AND (([address] = @original_address) OR ([address] IS NULL AND @original_address IS NULL)) AND (([marks_10] = @original_marks_10) OR ([marks_10] IS NULL AND @original_marks_10 IS NULL)) AND (([marks_12] = @original_marks_12) OR ([marks_12] IS NULL AND @original_marks_12 IS NULL)) AND (([grade_ug] = @original_grade_ug) OR ([grade_ug] IS NULL AND @original_grade_ug IS NULL)) AND (([grade_pg] = @original_grade_pg) OR ([grade_pg] IS NULL AND @original_grade_pg IS NULL)) AND (([achievement] = @original_achievement) OR ([achievement] IS NULL AND @original_achievement IS NULL)) AND (([reference1] = @original_reference1) OR ([reference1] IS NULL AND @original_reference1 IS NULL)) AND (([reference2] = @original_reference2) OR ([reference2] IS NULL AND @original_reference2 IS NULL)) AND (([reference3] = @original_reference3) OR ([reference3] IS NULL AND @original_reference3 IS NULL))" 
			oninserting="SqlDataSource_Student_Inserting">
			<DeleteParameters>
				<asp:Parameter Name="original_id" Type="Int32" />
				<asp:Parameter Name="original_name" Type="String" />
				<asp:Parameter Name="original_gender" Type="String" />
				<asp:Parameter DbType="Date" Name="original_dob" Type="DateTime" />
				<asp:Parameter Name="original_address" Type="String" />
				<asp:Parameter Name="original_marks_10" Type="Double" />
				<asp:Parameter Name="original_marks_12" Type="Double" />
				<asp:Parameter Name="original_grade_ug" Type="String" />
				<asp:Parameter Name="original_grade_pg" Type="String" />
				<asp:Parameter Name="original_achievement" Type="String" />
				<asp:Parameter Name="original_reference1" Type="String" />
				<asp:Parameter Name="original_reference2" Type="String" />
				<asp:Parameter Name="original_reference3" Type="String" />
			</DeleteParameters>
			<InsertParameters>
				<asp:Parameter Name="name" Type="String" />
				<asp:Parameter Name="gender" Type="String" />
				<asp:Parameter DbType="Date" Name="dob" />
				<asp:Parameter Name="address" Type="String" />
				<asp:Parameter Name="marks_10" Type="Double" />
				<asp:Parameter Name="marks_12" Type="Double" />
				<asp:Parameter Name="grade_ug" Type="String" />
				<asp:Parameter Name="grade_pg" Type="String" />
				<asp:Parameter Name="achievement" Type="String" />
				<asp:Parameter Name="reference1" Type="String" />
				<asp:Parameter Name="reference2" Type="String" />
				<asp:Parameter Name="reference3" Type="String" />
			</InsertParameters>
			<UpdateParameters>
				<asp:Parameter Name="name" Type="String" />
				<asp:Parameter Name="gender" Type="String" />
				<asp:Parameter DbType="Date" Name="dob" />
				<asp:Parameter Name="address" Type="String" />
				<asp:Parameter Name="marks_10" Type="Double" />
				<asp:Parameter Name="marks_12" Type="Double" />
				<asp:Parameter Name="grade_ug" Type="String" />
				<asp:Parameter Name="grade_pg" Type="String" />
				<asp:Parameter Name="achievement" Type="String" />
				<asp:Parameter Name="reference1" Type="String" />
				<asp:Parameter Name="reference2" Type="String" />
				<asp:Parameter Name="reference3" Type="String" />
				<asp:Parameter Name="original_id" Type="Int32" />
				<asp:Parameter Name="original_name" Type="String" />
				<asp:Parameter Name="original_gender" Type="String" />
				<asp:Parameter DbType="Date" Name="original_dob" />
				<asp:Parameter Name="original_address" Type="String" />
				<asp:Parameter Name="original_marks_10" Type="Double" />
				<asp:Parameter Name="original_marks_12" Type="Double" />
				<asp:Parameter Name="original_grade_ug" Type="String" />
				<asp:Parameter Name="original_grade_pg" Type="String" />
				<asp:Parameter Name="original_achievement" Type="String" />
				<asp:Parameter Name="original_reference1" Type="String" />
				<asp:Parameter Name="original_reference2" Type="String" />
				<asp:Parameter Name="original_reference3" Type="String" />
			</UpdateParameters>
		</asp:SqlDataSource>
    </form>
</body>
</html>