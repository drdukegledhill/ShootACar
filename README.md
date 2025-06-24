# Shoot-a-Car: A Turret-Shooting Taster in Unreal Engine 5

Welcome! This taster session is designed to give you a hands-on introduction to game development with Unreal Engine 5. You will learn the basics of the engine, how to work with existing assets, and how to implement simple game mechanics.

![A car with a turret mounted on its roof](docs/images/turretoncar.png)

## Session Goals

By the end of this activity, you will have:
- A foundational understanding of the Unreal Engine 5 interface.
- Experience in loading and working with a game template.
- An appreciation for rapid prototyping using pre-existing assets.
- Familiarity with the Unreal Engine Marketplace (now Fab) and project templates.

## 1. Getting Started with Unreal Engine

Unreal Engine is the powerhouse behind many of today's most popular games, from *Fortnite* and *PUBG* to critically acclaimed titles like *The Last of Us Part I* and *Final Fantasy VII Remake*.

![The Epic Games Launcher](docs/images/epiclauncher.png)

**Installation:**
- **At home:** Download and install the Epic Games Launcher from [epicgames.com](https://www.epicgames.com). In the launcher, navigate to the "Unreal Engine" tab and install version 5.4 or later.
- **On campus:** Unreal Engine is already installed and ready to go.

**Engine Interface:**
The Unreal Engine interface can seem complex at first. For a helpful overview, you can watch this introductory video. Although it was made for Unreal Engine 4, most of the concepts are still applicable in UE5.
- [Introduction to the Unreal Engine Interface](https://youtu.be/CmbGUIdz7GU)

## 2. Project Overview: Adding a Turret to a Car

In this project, we're going to modify a pre-built vehicle template by adding a fully functional turret. The goal is to create a simple, fun mechanic where you can shoot at other cars.

We will be working with the `ShootACar_blank` project.

### Our Plan:
1.  **Find a Turret:** We'll use a pre-made asset from the marketplace.
2.  **Animate the Turret:** We'll use the turret's skeletal bones to allow it to move.
3.  **Create a Projectile:** We'll borrow a projectile from the First-Person template.
4.  **Implement Firing:** We'll set up input controls to fire the projectile from a socket on the turret.
5.  **Add Physics:** We'll make the projectile apply a force to any car it hits.
6.  **(Optional) Further Enhancements:**
    -   Add visual effects (VFX) for firing and impacts.
    -   Modify the projectile's properties.
    -   Implement a scoring system or user interface (UI).
    -   Add sound effects.

## 3. Implementation Steps

### The Turret Asset

The project already includes a "Sci-Fi Turret" asset, originally from the Unreal Engine Marketplace. You can find it in the `Content/SciFiturretasset` folder.

> #### Discussion Point: Using Pre-made Assets
> In professional game development, using pre-made assets is a common practice, especially for rapid prototyping. This involves considering:
> - **Legal & Ethical:** Licensing agreements and whether you can use free assets in a commercial product.
> - **Commercial:** The cost-benefit of buying assets versus creating them in-house.
> - **Technical:** Ensuring assets are well-optimised (e.g., polygon count) and technically sound.

![The Fab marketplace page for the turret asset](docs/images/fabturret.png)

### Adding the Turret to the Car

We'll add the turret as a component to the player's car. The car is a Blueprint asset located at `Content/VehicleTemplate/Blueprints/StarterWheeledVehiclePawnBP`.

1.  Open the `StarterWheeledVehiclePawnBP` Blueprint.
2.  Add a **Poseable Mesh** component to the Blueprint. *Challenge: Why use a Poseable Mesh instead of a Skeletal Mesh?*
3.  In the Details panel for the new component, set the **Skeletal Mesh** to `SKM_scifiturret`.
4.  Position and scale the turret on the car's roof. A good starting point is `Location: (-33, 0, 116)` and `Scale: (0.5, 0.5, 0.5)`.

![Adding the poseable mesh component in the Blueprint editor](docs/images/addposeablemesh.png)

### Animating the Turret

To make the turret move, we need to rotate its bones.

1.  Open the `SKM_scifiturret` Skeletal Mesh asset to inspect its skeleton. The bone we want to rotate is named `bn_head`.
2.  While the Skeletal Mesh is open, create a **Socket** to define where projectiles will spawn from. Right-click on the `bn_headbarrelend` bone and select "Add Socket". You can leave the default name. Move the socket so it's positioned just in front of the barrel. *Challenge: Why is it important to place the socket slightly away from the mesh?*

![The turret's bone hierarchy](docs/images/turretbones.png)
![The turret socket at the end of the barrel](docs/images/turretsocket.png)

Now, let's add the rotation logic to the `StarterWheeledVehiclePawnBP` Event Graph.

> **Note on Best Practices:** For this taster, we're using the `Event Tick` to quickly prototype the turret's rotation. In a real-world project, this would be inefficient. A better approach would be to use a more optimised animation system and event-driven controls.

![The Blueprint graph for turret rotation](docs/images/turretrotation.png)

### Firing Projectiles

We'll use a pre-made projectile from the First-Person template, which is already included in the `SciFiturretasset` folder.

First, we need to set up an input for firing. This project uses the older input system.
1.  Go to **Project Settings > Engine > Input**.
2.  Add a new **Action Mapping** named `FireWeapon` and assign it to the **Left Mouse Button**.

![The input settings for the fire weapon action](docs/images/input.png)

Now, let's add the firing logic to the `StarterWheeledVehiclePawnBP` Event Graph.

![The Blueprint graph for firing the projectile](docs/images/fire.png)

Finally, for a bit of fun, you can increase the impact force of the projectile.
1.  Open the `BP_FirstPersonProjectile` Blueprint.
2.  Find the `Impulse` variable or the relevant node in the graph and increase its value. Experiment to see what works best!

![The impulse setting in the projectile Blueprint](docs/images/impulseprojectile.png)

## That's a Wrap!

You've now successfully added a functional turret to a car in Unreal Engine. Feel free to continue experimenting with the project and exploring what else you can create.

---
*v.250623.car*
*© Dr Duke Gledhill*
