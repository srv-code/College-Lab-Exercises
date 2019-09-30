using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class AddingNames : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {}
    
    protected void Button_Add_Click(object sender, EventArgs e) {
        foreach (int idx in ListBox_Source.GetSelectedIndices()) {
            ListBox_Dest.Items.Add(ListBox_Source.Items[idx]);
			System.Diagnostics.Debug.WriteLine("Added: idx={0}, value={1}", idx, ListBox_Source.Items[idx]);
        }
    }
}