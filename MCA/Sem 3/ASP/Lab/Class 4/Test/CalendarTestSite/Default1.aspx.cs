using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;


public partial class Calendar1 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Calendar_Test_DayRender(object sender, DayRenderEventArgs e) {
        Debug.WriteLine("Calendar_Test_DayRender invoked: date selected: " + e.Day.Date.ToShortDateString());
    }

    protected void Calendar_Test_SelectionChanged(object sender, EventArgs e) {
        Debug.Print("Calendar_Test_SelectionChanged invoked: date selected: {0}", 
            Calendar_Test.SelectedDate.ToShortDateString());
    }

    protected void Calendar_Test_VisibleMonthChanged(object sender, MonthChangedEventArgs e) {
        Debug.WriteLine("Calendar_Test_VisibleMonthChanged invoked");
    }

    protected void Button1_Click(object sender, EventArgs e) {
        Page.Response.Write("date=" + Calendar_Test.SelectedDate.Ticks);
    }
}