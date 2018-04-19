// Draws a japanese snow covered fractal tree in front of the rising sun

open System
open System.Drawing
open System.Windows.Forms

let width = 1920
let height = 1080

let window = new Form(Width = width, Height = height, Text = "Fractal Tree - Chris")
let image = new Bitmap(width, height, System.Drawing.Imaging.PixelFormat.Format32bppArgb)
let box = new PictureBox(BackColor=Color.White, Dock=DockStyle.Fill)
let graphic = Graphics.FromImage(image)

box.Image <- image
window.Controls.Add(box)

graphic.CompositingMode <- System.Drawing.Drawing2D.CompositingMode.SourceCopy

let angle = 1.57
let length = 200.
let random = System.Random()

let getRandomInRange x y = double(random.Next(x, y)) * 0.1

let getNewLength x y = x * y

let rec drawTree (target : Graphics) (x:int) (y:int) (angle:float) (length:double) itr =
    
    let xlength = length * cos(angle)
    let ylength = length * sin(angle)

    let floatx = float(x) + xlength 
    let floaty = float(y) - ylength 

    let x2 = int(floatx)
    let y2 = int(floaty)

    let alpha = itr * 17 
    let penCurrent = new Pen(Color.FromArgb(alpha, Color.Black), float32(itr))

    target.DrawLine(penCurrent, x, y, x2, y2)
    target.DrawLine(penCurrent, x, y, x2, y2)

    if itr > 0 then drawTree target x2 y2 (angle + (getRandomInRange 2 5)) (getNewLength length (getRandomInRange 6 10)) (itr - 1)
                    drawTree target x2 y2 (angle - (getRandomInRange 2 5)) (getNewLength length (getRandomInRange 6 10)) (itr - 1)

let drawSun (target : Graphics) =
    target.FillEllipse(new SolidBrush(Color.Red), 560, 100, 800, 800)

let drawGround (target : Graphics) =
    target.FillRectangle(new SolidBrush(Color.Black), 0, height - 100, width, 500)

let render (target : Graphics) =
    drawSun target
    drawTree target 960 height angle length 15
    drawGround target

[<EntryPoint>]
let main argv = 
    render graphic

    window.ShowDialog()

    0 // return an integer exit code
