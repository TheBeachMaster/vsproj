using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace UserAuth1
{
    public partial class ListItemPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //CheckBoxList1.Items[].Attributes.Add("class", "checkbox");
            for (int i = 0; i < CheckBoxList1.Items.Count; i++)
            {
                CheckBoxList1.Items[i].Attributes.Add("class", "checkbox");
            }

            Button1.Attributes.Add("class", "btn btn-primary btn-lg");
            //SubButton.Attributes.Add("class","btn btn-info btn-lg");
        }

       
        protected void ItemSumSub(object sender, EventArgs e)
        {
            Int32 totalvalue = 0;
            //Loop through items in checkboxlist
            for (int i = 0; i < CheckBoxList1.Items.Count; i++)
            {
                //check if particular items is selected or not
                if (CheckBoxList1.Items[i].Selected)
                {
                    //If selected then add the values to textbox
                    totalvalue += Convert.ToInt32(CheckBoxList1.Items[i].Value);

                   
                }
            }

            //totalvalue = Sosa.
            Label1.Text += totalvalue.ToString();
            totalvalue = 0;
        }
    }
}