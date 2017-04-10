<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ListItemPage.aspx.cs" Inherits="UserAuth1.ListItemPage" %>

    <!DOCTYPE html>


    <html xmlns="http://www.w3.org/1999/xhtml">

    <head runat="server">
        <title></title>

        <link href="Contents/bootstrap-theme.css" rel="stylesheet" />
        <link href="Contents/bootstrap.min.css" rel="stylesheet" />
        <script src="Scripts/bootstrap.js"></script>
        <script src="Scripts/bootstrap.min.js"></script>
        <script src="Scripts/jQuery.js"></script>
        <script src="Scripts/json2js.js"></script> 
       <script type="text/javascript" src="http://cdn.jsdelivr.net/json2/0.1/json2.js"></script>
    </head>

    <body>
        <form id="form1" runat="server">
            <!--
            <div>
                <asp:CheckBoxList ID="CheckBoxList1" runat="server">

                    <asp:ListItem Value="10"> $ 10 </asp:ListItem>
                    <asp:ListItem Value="20"> $ 20 </asp:ListItem>
                    <asp:ListItem Value="30"> $ 30 </asp:ListItem>
                    <asp:ListItem Value="40"> $ 40 </asp:ListItem>
                    <asp:ListItem Value="50"> $ 50 </asp:ListItem>
                    <asp:ListItem Value="60"> $ 60 </asp:ListItem>
                </asp:CheckBoxList>
            </div>


            <div>

                <asp:Button ID="Button1" runat="server" Text="Sum Up and Submit" OnClick="ItemSumSub" />
            </div>
            <asp:Label ID="Label1" runat="server" Text="Total : "></asp:Label>
-->

            <div class="container">
                <h2>Arthur's Super Awesome Restaurant</h2>
                <table class="table">
                    <thead>
                        <tr>
                            <th>Selected</th>
                            <th>Food Item</th>
                            <th>Quantity</th>
                            <th>Price ($)</th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr>
                             <td><input type="checkbox" value=""></td>
                            <td>Chapo Mix</td>
                            <td>3</td>
                            <td>3.99</td>
                        </tr>
                        <tr>
                            <td><input type="checkbox" value=""></td>
                            <td>Beast</td>
                            <td>5</td>
                            <td>20.99</td>   
                        </tr>
                        <tr>
                            <td><input type="checkbox" value=""></td>
                            <td>KDF</td>
                            <td>4</td>
                            <td>10.89</td>
                        </tr>
                        <tr>
                            <td><input type="checkbox" value=""></td>
                            <td>Pilau Njeri</td>
                            <td>3</td>
                            <td>2.50</td>
                        </tr>
                        <tr>
                            <td><input type="checkbox" value=""></td>
                            <td>Chipo Mwitu</td>
                            <td>1</td>
                            <td>14.79</td>
                        </tr>
                        
                    </tbody>
                </table>

            </div>
            <div>
                <asp:Button ID="Button2" CssClass="btn btn-lg btn-primary" Text="Submit" runat="server" OnClick="ItemSumSub" />
            </div>
        </form>
    </body>

    </html>