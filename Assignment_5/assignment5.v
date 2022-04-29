module assignment5(
input wire u,
input wire v,
input wire w,
input wire z,

output wire redled,
output wire greenled,
output wire blueled);

reg f;
assign f = w&z | v&z | u&v&(!W) | (!u)&v&w; 
assign redled = (f == 0) ? 1:0;
assign greenled = (f == 1) ? 1:0;
endmodule
