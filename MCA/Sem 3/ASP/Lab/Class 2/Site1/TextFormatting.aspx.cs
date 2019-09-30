using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Text;
using System.Drawing;

public partial class TextFormatting : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {}
    
    protected void Button_Apply_Click(object sender, EventArgs e) {
        StringBuilder sb = new StringBuilder();
        sb  .Append("Name: ").Append(TextBox_Name.Text)
            .AppendLine()
            .Append("Text: ").Append(TextBox_Text.Text);

        TextBox_Output.Text = sb.ToString();

        TextBox_Output.Font.Bold = CheckBox_Bold.Checked;
        TextBox_Output.Font.Italic = CheckBox_Italic.Checked;
        TextBox_Output.Font.Underline = CheckBox_Underline.Checked;

        TextBox_Output.ForeColor = Color.FromName(RadioButtonList_ForeColors.SelectedValue);
        TextBox_Output.BackColor = Color.FromName(RadioButtonList_BackColors.SelectedValue);
    }
}