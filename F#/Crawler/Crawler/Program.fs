// Learn more about F# at http://fsharp.org
// See the 'F# Tutorial' project for more help.
open FSharp.Data

[<Literal>]
let url = @"https://www.jumia.co.ke/desktop-computers/hp/"
type HPData = HtmlProvider<url>

let func() = 
      let data = HPData.GetSample()
      data.Lists.List10.Values


[<EntryPoint>]
let main argv = 
    printfn "%A" argv
    0 // return an integer exit code
