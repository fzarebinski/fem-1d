# MES 1D
This is small C++ project to analyse final element method for 1D with different layers. I did it for my studies and share it to my mates from AGH.

## How to run?
Nice to have is Visual Studio 2017, because `.sln` file is capable with this and futures versions of this IDE. Solution will generate you good structure of filters. It's really helpful to get ideas how to organise your own code.

## How can I work with `data.txt` file?
Structure of this file is very quick and flexible. You can use as many layers as you need, but you have to be careful about correct file structure. It's important to properly work and... to get good results :)

More informations about file you can get by analyse `Global` class.
> NH Ta q ALPHA
>
> NE L K S
>
> NE L K S
>
> NE L K S
>
> ...

Remember that the most important to `Global` class, where you can find reader for file are `NH` and `NE` arguments. `NH` should be sum of all `NE` increased by 1. If you have 11 nodes, you need 10 elements. If you declare 11 nodes and create 20 elements, software will use only 10 first elements.

## Is this working?
Yes, it is. If you correct use this, remember that it's non-profit project to get credit. This isn't big software.

## Who made this?
All lines of codes are mine. Also `MESMath` class with gauss. Please use this as roadmap to create your app, not as your own project. I want to help you, so please be fair with me.
