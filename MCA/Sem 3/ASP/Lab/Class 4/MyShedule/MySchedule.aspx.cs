using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Collections;
using System.Diagnostics;
using System.Drawing;


public partial class MySchedule : System.Web.UI.Page
{
	Hashtable scheduleDates;

    protected void Page_Load(object sender, EventArgs e) {
		Debug.Print("[page load : {0}]", DateTime.Now.Millisecond);

		Debug.Print("Loading scheduleDates...");
		scheduleDates  = new Hashtable();
		scheduleDates[new DateTime(2019, 8, 8)] = "Visit doctor";
		scheduleDates[new DateTime(2019, 8, 11)] = "Go to groceries";
		scheduleDates[new DateTime(2019, 9, 10)] = "Maths Test";
    }

    protected void Calendar_MySeptSchedule_DayRender(object sender, DayRenderEventArgs e) {
		string evt = (string)scheduleDates[e.Day.Date];
		if (evt != null) {
			e.Cell.BackColor = Color.LightGreen;
			Label lbl = new Label();
			lbl.CssClass = "event_day";
			lbl.Text = "<br/>" + evt;
			e.Cell.Controls.Add(lbl);
		}
    }
}